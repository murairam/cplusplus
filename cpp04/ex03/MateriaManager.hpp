#ifndef MATERIAMANAGER_HPP
#define MATERIAMANAGER_HPP

class AMateria;

class MateriaManager {
private:
    static AMateria* _orphanedMaterias[100];
    static int _count;
    
    MateriaManager();  // Private constructor

public:
    static void store(AMateria* materia);
    static void cleanup();
    static int getOrphanedCount();
    static bool isFull();
};

#endif