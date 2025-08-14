#include "Character.hpp"


Character::Character(std::string name) : _name(name) {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
}

Character::Character(const Character& other) : _name(other._name){
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i] != NULL) {
            _inventory[i] = other._inventory[i]->clone();  
        } else {
            _inventory[i] = NULL;
        }
    }
}

Character& Character::operator=(const Character& other){
    if(this == &other){
        return *this;
    }

    for (int i = 0; i < 4; i++){
        if (_inventory[i] != NULL) {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }

    _name = other._name;

    for (int i = 0; i < 4; i++){
        if (other._inventory[i] != NULL) {
            _inventory[i] = other._inventory[i]->clone();  
        } else {
            _inventory[i] = NULL;
        }
    }
    
    return *this;
}

Character::~Character(){
    for (int i = 0; i < 4; i++){
        if (_inventory[i] != NULL) {
            delete _inventory[i];
            _inventory[i] = NULL;
        }   
    }
}

std::string const & Character::getName() const{
    return this->_name;
}

void Character::equip(AMateria* m){
    if (!m)
        return ;
    int slot = findFirstEmptySlot();
    if (slot != -1)
        _inventory[slot] = m;
}

void Character::unequip(int idx){
    if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
        _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
    if (idx >=0 && idx < 4 && _inventory[idx] != NULL)
        _inventory[idx]->use(target);
}

int Character::findFirstEmptySlot() const{
    for(int i = 0;i < 4; i++){
        if (_inventory[i] == NULL)
            return i;
    }
    return -1;
}


