/*
 *  Copyright (c) 2015, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#pragma once

#include <chrono>
#include <inttypes.h>
#include <proxygen/lib/http/session/TTLBAStats.h>

namespace proxygen {

// This may be retired with a byte events refactor
class HTTPSessionStats : public TTLBAStats {
 public:
  ~HTTPSessionStats() noexcept override {}

  virtual void recordTransactionOpened() noexcept = 0;
  virtual void recordTransactionClosed() noexcept = 0;
  virtual void recordTransactionsServed(uint64_t) noexcept = 0;
  virtual void recordSessionReused() noexcept = 0;
  virtual void recordSessionIdleTime(std::chrono::seconds) noexcept {};
};

}
