/*********************************************************************
 * @file  observer/observer.h
 *********************************************************************/

#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;

/*!
 * \brief The Observer class is an interface that defines the methods that
 * the Subject will use to notify all of its registered observers.
 */
class Observer
{
public:
    /*!
     * \brief Called by a Subject object to notify the Observer of a change.
     * This method is called by a Subject object to notify the Observer of a change.
     * The Observer should then update its state accordingly.
     *
     * \param subject The Subject object that has changed.
     */
    virtual void update(const Subject * subject) = 0;

    /*!
     * \brief Destructor.
     * The destructor is declared as virtual to ensure that objects are properly destroyed when deleted through
     * a pointer to an Observer.
     */
    virtual ~Observer() = default;

    /*!
     * \brief Copy constructor.
     * The copy constructor is declared as default because an Observer object can be safely copied.
     */
    Observer(const Observer &) = default;

    /*!
     * \brief Move constructor.
     * The move constructor is declared as default because an Observer object can be safely moved.
     */
    Observer(Observer &&) = default;

    /*!
     * \brief Copy assignment operator.
     * The copy assignment operator is declared as default because an Observer object can be safely copied.
     */
    Observer & operator=(const Observer &) = default;

    /*!
     * \brief Move assignment operator.
     * The move assignment operator is declared as default because an Observer object can be safely moved.
     */
    Observer & operator=(Observer &&) = default;

    /*!
     * \brief Default constructor.
     * The default constructor is declared as default because an Observer object can be safely created
     * without any specific initialization.
     */
    Observer() = default;
};

#endif // OBSERVER_H
