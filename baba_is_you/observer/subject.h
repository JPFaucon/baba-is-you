/*********************************************************************
 * @file  observer/subject.h
 *********************************************************************/

#ifndef SUBJECT_H
#define SUBJECT_H

#include <set>

class Observer;

/*!
 * \brief The Subject class provides a way for the observers to
 * register and unregister themselves, and it defines the methods
 * that the observers must implement in order to receive notifications.
 */
class Subject
{
protected:
    /*!
     * \brief observers_ The observers registered to the subject.
     */
    std::set<Observer *> observers_ { };

public:
    virtual ~Subject() = default;
    Subject(const Subject &) = default;
    Subject(Subject &&) = default;
    Subject & operator=(const Subject &) = default;
    Subject & operator=(Subject &&) = default;

    /*! \brief Adds an observer to the collection of observers registered to the subject.
     *
     *  \param observer The observer to add to the collection.
     */
    virtual void addObserver(Observer * observer) final;

    /*! \brief Removes an observer from the collection of observers registered to the subject.
     *
     *  \param observer The observer to remove from the collection.
     */
    virtual void removeObserver(Observer * observer) final;

protected:

    /*!
     * \brief Default constructor.
     */
    Subject() = default;

    /*! \brief Notifies all observers in the collection of a change to the subject's state.
     *
     *  This method is protected because it should only be called by derived classes in response to changes in their state.
     */
    virtual void notifyObservers() const final;
};

#endif // SUBJECT_H
