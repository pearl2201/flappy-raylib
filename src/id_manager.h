// src/IdManager.h
#pragma once

#include <cstdint>
#include <queue> // For a pool of free IDs
#include <mutex> // For thread safety

class IdManager {
public:
    static IdManager& getInstance();

    IdManager(const IdManager&) = delete;
    IdManager& operator=(const IdManager&) = delete;

    uint64_t generateId();
    void returnId(uint64_t id); // Method to return a freed ID

private:
    IdManager();
    ~IdManager() = default;

    uint64_t m_nextId;
    std::queue<uint64_t> m_freeIds; // Pool of reusable IDs
    std::mutex m_mutex; // Protects m_nextId and m_freeIds
};