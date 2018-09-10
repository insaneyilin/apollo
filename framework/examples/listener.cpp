/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "cybertron/cybertron.h"
#include "cybertron/proto/chatter.pb.h"

void MessageCallback(
    const std::shared_ptr<apollo::cybertron::proto::Chatter>& msg) {
  AINFO << "Received message seq-> " << msg->seq();
  AINFO << "msgcontent->" << msg->content();
}

int main(int argc, char *argv[]) {
  // init cybertron framework
  apollo::cybertron::Init(argv[0]);  

  // create listener node
  auto listener_node = apollo::cybertron::CreateNode("listener");
  // create listener
  auto listener =
      listener_node->CreateReader<apollo::cybertron::proto::Chatter>(
          "channel/chatter", MessageCallback);

  apollo::cybertron::WaitForShutdown();
  return 0;
}