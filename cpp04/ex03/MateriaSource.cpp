#include "MateriaSource.hpp"
#include "AMateria.hpp" 

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; i++) {
        _templates[i] = NULL;
    }
}
MateriaSource::MateriaSource(const MateriaSource& other){
    for (int i = 0; i < 4; i++) {
        if (other._templates[i] != NULL) {
            _templates[i] = other._templates[i]->clone();  
        } else {
            _templates[i] = NULL;
        }
    }
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other){
        if(this == &other){
        return *this;
    }

    for (int i = 0; i < 4; i++){
        if (_templates[i] != NULL) {
            delete _templates[i];
            _templates[i] = NULL;
        }
    }

    for (int i = 0; i < 4; i++){
        if (other._templates[i] != NULL) {
            _templates[i] = other._templates[i]->clone();  
        } else {
            _templates[i] = NULL;
        }
    }
    
    return *this;

}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; i++){
        if (_templates[i] != NULL) {
            delete _templates[i];
            _templates[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria* m){
    if (!m)
        return ;
    int slot = findFirstEmptySlot();
    if (slot != -1)
        _templates[slot] = m;
    else
        delete  m;

}
AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++) {
        if (_templates[i] != NULL && _templates[i]->getType() == type) {
            return _templates[i]->clone();
        }
    }
    return NULL;
}

int MateriaSource::findFirstEmptySlot() const{
    for(int i = 0;i < 4; i++){
        if (_templates[i] == NULL)
            return i;
    }
    return -1;
}
