/*
 *  Copyright 2012 The WebRTC Project Authors. All rights reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef API_ALPHACC_CONFIG_H_
#define API_ALPHACC_CONFIG_H_

#include <string>

namespace alphaCC {

struct AlphaCCConfig {
  AlphaCCConfig() = default;
  ~AlphaCCConfig() = default;
  // The server to connect
  std::string conn_server_ip;
  int conn_server_port = 0;
  // Connect to the server without user intervention.
  bool conn_autoconnect = false;
  // Call the first available other client on
  // the server without user intervention. Note: this flag should be set
  // to true on ONLY one of the two clients.
  bool conn_autocall = false;
  // The time in seconds before close automatically (always run
  // if autoclose=0)"
  int conn_autoclose = 0;

  // Redis server configuration
  std::string redis_ip;
  int redis_port = 0;
  // Redis session id
  std::string redis_sid;
  int redis_update_duration_ms = 500;

  int bwe_feedback_duration_ms = 200;
  std::string onnx_model_path;

  enum class VideoSourceOption {
    kVideoDisabled,
    kWebcam,
  } video_source_option;
};

// Get alphacc global configurations
const AlphaCCConfig* GetAlphaCCConfig();

// Parse configurations files from |file_path|
bool ParseAlphaCCConfig(const std::string& file_path);

}  // namespace alphaCC

#endif  // API_ALPHACC_CONFIG_H_
