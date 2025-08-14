#include "MateriaManager.hpp"
#include "AMateria.hpp"

// Static member definitions
AMateria* MateriaManager::_orphanedMaterias[100] = {NULL};
int MateriaManager::_count = 0;

void MateriaManager::store(AMateria* materia) {
    if (!materia) return;
    
    if (_count >= 100) {
        cleanup();  // Auto-cleanup when full
    }
    
    _orphanedMaterias[_count] = materia;
    _count++;
}

void MateriaManager::cleanup() {
    for (int i = 0; i < _count; i++) {
        if (_orphanedMaterias[i]) {
            delete _orphanedMaterias[i];
            _orphanedMaterias[i] = NULL;
        }
    }
    _count = 0;
}

int MateriaManager::getOrphanedCount() {
    return _count;
}

bool MateriaManager::isFull() {
    return _count >= 100;
}