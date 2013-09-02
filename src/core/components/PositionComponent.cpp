#include "PositionComponent.h"

PositionComponent::PositionComponent() {
    this->parentPosition = NULL;
}

PositionComponent::PositionComponent(float x, float y) {
    this->pos.setX(x);
    this->pos.setY(y);

    this->parentPosition = NULL;
}

Vector2D PositionComponent::getPosition() {
    Vector2D position;
        
    if (this->parentPosition != NULL) {
        position = (this->parentPosition->getPosition());
    }

    position = position + this->pos;

    return position;
}

void PositionComponent::setParentPosition(PositionComponent * position) {
    this->parentPosition = position;
    
    // Convert the actual position from global to relative, or the object will move from its actual position
    Vector2D parentRealPosition;
    Vector2D objectRealPosition;
    Vector2D objectRelativePosition;
    
    parentRealPosition = position->getPosition();
    objectRealPosition = this->pos;
    objectRelativePosition = objectRealPosition - parentRealPosition;
    
    this->pos = objectRelativePosition;
}

void PositionComponent::removeParentPosition() {
    if (this->parentPosition != NULL) {
        // Convert from local position to global position
        Vector2D globalPosition = this->getPosition();
        
        this->pos = globalPosition;
        
        this->parentPosition = NULL;
    }
}
