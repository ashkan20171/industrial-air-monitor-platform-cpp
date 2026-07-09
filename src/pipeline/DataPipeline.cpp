#include "DataPipeline.h"
#include <algorithm>

namespace ashkan::pipeline {
DataPipeline::DataPipeline(std::size_t maxBufferSize) : m_maxBufferSize(maxBufferSize) {}

void DataPipeline::pushReading(const AnalyzerReading& reading) {
    std::vector<Subscriber> subscribersCopy;
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_buffer.push_back(reading);
        while (m_buffer.size() > m_maxBufferSize) m_buffer.pop_front();
        subscribersCopy = m_subscribers;
    }
    for (auto& s : subscribersCopy) if (s.callback) s.callback(reading);
}

void DataPipeline::subscribe(const std::string& name, ReadingCallback callback) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_subscribers.push_back({name, std::move(callback)});
}

std::vector<AnalyzerReading> DataPipeline::recent(std::size_t limit) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::vector<AnalyzerReading> out;
    const auto n = std::min(limit, m_buffer.size());
    out.reserve(n);
    auto it = m_buffer.end() - static_cast<std::ptrdiff_t>(n);
    for (; it != m_buffer.end(); ++it) out.push_back(*it);
    return out;
}
std::size_t DataPipeline::size() const { std::lock_guard<std::mutex> lock(m_mutex); return m_buffer.size(); }
}
