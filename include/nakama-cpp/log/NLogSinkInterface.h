/*
 * Copyright 2019 The Nakama Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <string>
#include <memory>

namespace Nakama {

    enum class NAKAMA_API NLogLevel
    {
        Trace    = 0,
        Debug    = 1,
        Info     = 2,
        Warn     = 3,
        Error    = 4,
        Fatal    = 5
    };

    struct NAKAMA_API NLogMessage
    {
        NLogMessage() = default;
        NLogMessage(const std::string& msg, NLogLevel lvl) :
            message(msg), level(lvl) {};

        std::string message;
        NLogLevel level;
    };

    class NAKAMA_API NLogSinkInterface
    {
    public:
        NLogSinkInterface() {}
        virtual ~NLogSinkInterface() {}

        virtual void log(const NLogMessage& msg) = 0;
        virtual void flush() = 0;

        void setLevel(NLogLevel level) { _level = level; }
        NLogLevel getLevel() const { return _level; }

    protected:
        NLogLevel _level = NLogLevel::Info;
    };

    using NLogSinkPtr = std::shared_ptr<NLogSinkInterface>;

}
