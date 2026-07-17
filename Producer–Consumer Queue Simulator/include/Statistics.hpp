#pragma once

#include <pthread.h>

struct StatisticsSnapshot {
    int produced{};
    int consumed{};
    int producerWaits{};
    int consumerWaits{};
    double executionTime{};
};

class Statistics {
public:
    Statistics();
    ~Statistics();
    Statistics(const Statistics&) = delete;
    Statistics& operator=(const Statistics&) = delete;

    void reset();
    void recordProduced();
    void recordConsumed();
    void recordProducerWait();
    void recordConsumerWait();
    StatisticsSnapshot snapshot(double executionTime) const;

private:
    mutable pthread_mutex_t mutex_{};
    int produced_{};
    int consumed_{};
    int producerWaits_{};
    int consumerWaits_{};
};
