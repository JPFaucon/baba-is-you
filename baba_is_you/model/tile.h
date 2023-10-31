/*********************************************************************
 * @file  model/tile.h
 *********************************************************************/

#ifndef TILE_H
#define TILE_H

#include <vector>
#include <list>
#include <algorithm>

#include "observer/subject.h"

class Component;
class Rule;
enum class MaterialType;

/*!
 * \brief The Tile class represents one tile of the board. One tile
 * can contain several material components and only one text
 * component.
 */
class Tile : public Subject
{
    /*!
     * \brief components_ All the components that are on that tile.
     */
    std::vector<Component *> components_ { };

public:
    /*!
     * \brief Default constructor for a Tile object.
     */
    Tile() = default;

    /*!
    * \brief Constructs a Tile object with the given components.
    * \param count The number of components to add to the tile.
    * \param ... The list of Component pointers to add to the tile.
    */
    Tile(unsigned int count, ...);
//    ~Tile();

    /*!
     *  \brief Returns the list of components on the tile.
     *  \return A const reference to the list of components on the tile.
     */
    const std::vector<Component *> &getComponents() const;

    /*!
     *  \brief Returns the component at the top of the current tile.
     *  \return A pointer to the component at the top of the current tile, or nullptr if the tile is empty.
     */
    const Component *getTopComponent() const;

    /*!
     *  \brief Returns a list of all You components on the tile.
     *  \return A list of pointers to all the "you" components on the tile.
     */
    std::vector<Component *> getYouComponents();

    /*!
     *  \brief Determines if the tile is steppable.
     *  \return true if the tile is steppable, false otherwise.
     */
    bool isSteppable();

    /*!
     *  \brief Determines if the tile is pushable.
     *  \return true if the tile is pushable, false otherwise.
     */
    bool isPushable();

    /*!
     *  \brief Determines if the tile contains a You component.
     *  \return true if the tile contains a You component, false otherwise.
     */
    bool containsYou();

    /*!
     *  \brief Determines if the tile contains a Win component.
     *  \return true if the tile contains a Win component, false otherwise.
     */
    bool containsWin();

    /*!
     *  \brief Determines if the tile contains a Kill component.
     *  \return true if the tile contains a Kill component, false otherwise.
     */
    bool containsKill();

    /*!
     *  \brief Adds a component to the tile.
     *  \param comp A reference to the Component to add to the tile.
     */
    void addComponent(Component&);

    /*!
     *  \brief Removes a component from the tile.
     *  \param comp A reference to the Component to remove from the tile.
     *  \throw std::invalid_argument if the component is not found on the tile.
     */
    void removeComponent(Component&);

    /*!
     *  \brief Executes the Rock in Water rule.
     *  If the tile contains a Rock component and a Water component,
     *  both components are removed from the tile.
     */
    void rockInWater();

    /*!
     * \brief Checks if the current tile contains a component with the "kill" property.
     * If such a component exists, the method removes any components on the tile that
     * have the "you" property.
     */
    void youInKill();

    /*!
     * \brief Updates the properties of each material component in the tile based
     * on a list of rules. For each material component, it clears its current
     * properties and adds new properties based on the rules that match its material type.
     * \param rules The list of appliable rules.
     */
    void updateComponentProperties(const std::list<Rule> & rules);

    /*!
     * \brief Updates the material type of each material component in the tile
     * that matches a specified material type. For each matching material component,
     * it creates a new material component with the new material type, and replaces
     * the old component with the new one.
     * \param materialType The type of the material that needs to be updated.
     * \param newMaterialType The new type of the material that will replace the old one.
     */
    void updateComponents(MaterialType, MaterialType);
};




#endif // TILE_H
