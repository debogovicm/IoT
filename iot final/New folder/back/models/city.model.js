export default function(sequelize, Sequelize) {
    const data = sequelize.define("Cities", {
        id: {type: Sequelize.INTEGER, primaryKey: true},
        name: {type: Sequelize.STRING}
    })

    return data
}