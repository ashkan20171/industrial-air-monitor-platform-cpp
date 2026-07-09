#pragma once
#include <functional>
#include <mutex>
#include <vector>
#include <deque>
#include <string>
#include "../core/AnalyzerReading.h"

namespace ashkan::pipeline {

class DataPipeline {
public:
    using ReadingCallback = std::function<void(const AnalyzerReading&)>;

    explicit DataPipeline(std::size_t maxBufferSize = 5000);
    void pushReading(const AnalyzerReading& reading);
    void subscribe(const std::string& name, ReadingCallback callback);
    std::vector<AnalyzerReading> recent(std::size_t limit = 100) const;
    std::size_t size() const;

private:
    struct Subscriber { std::string name; ReadingCallback callback; };
    std::size_t m_maxBufferSize;
    mutable std::mutex m_mutex;
    std::deque<AnalyzerReading> m_buffer;
    std::vector<Subscriber> m_subscribers;
};
}
