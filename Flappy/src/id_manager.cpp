// src/IdManager.cpp
#include "id_manager.h"
#include <iostream>

IdManager::IdManager() : m_nextId(1) {
    std::cout << "IdManager: Instance created." << std::endl;
}

IdManager& IdManager::getInstance() {
    static IdManager instance;
    return instance;
}

uint64_t IdManager::generateId() {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (!m_freeIds.empty()) {
        uint64_t id = m_freeIds.front();
        m_freeIds.pop();
        std::cout << "IdManager: Reusing ID: " << id << std::endl;
        return id;
    }
    std::cout << "IdManager: Generating new ID: " << m_nextId << std::endl;
    return m_nextId++;
}

void IdManager::returnId(uint64_t id) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_freeIds.push(id);
    std::cout << "IdManager: ID " << id << " returned to pool." << std::endl;
}