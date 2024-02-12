export default function(sequelize, Sequelize) {
    const data = sequelize.define("WeatherData", {
        id: {type: Sequelize.INTEGER, primaryKey: true},
        city: {type: Sequelize.STRING},
        temperature: {type: Sequelize.INTEGER},
        UVindex: {type: Sequelize.INTEGER},
        humidity: {type: Sequelize.INTEGER},
        cloudCover: {type: Sequelize.INTEGER},
        windSpeed: {type: Sequelize.INTEGER},
        windDirection: {type: Sequelize.INTEGER}
    })

    return data
}