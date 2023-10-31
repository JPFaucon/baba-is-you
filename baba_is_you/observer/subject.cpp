#include "observer/subject.h"
#include "observer/observer.h"

void Subject::addObserver(Observer * observer)
{
    observers_.insert(observer);
}

void Subject::removeObserver(Observer * observer)
{
    observers_.erase(observer);
}

void Subject::notifyObservers() const
{
    for (Observer * observer : observers_)
    {
        observer->update(this);
    }
}
