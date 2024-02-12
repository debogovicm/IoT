import cityConstructor from "./city.model.js"
import weatherDataConstructor from "./weatherData.model.js"
import dbConfig from "../config/db.config.js"

import { Sequelize } from "sequelize"

const sequelize = new Sequelize(dbConfig.DB, dbConfig.USER, dbConfig.PASSWORD, {
    host: dbConfig.HOST,
    dialect: dbConfig.dialect,
    operatorAliases: false,
    pool: {
        max: dbConfig.pool.max,
        min: dbConfig.pool.min,
        acquire: dbConfig.pool.acquire,
        idle: dbConfig.pool.idle
    }
});

const db = {};
db.Sequelize = Sequelize;
db.sequelize = sequelize;
db.city = cityConstructor(sequelize, Sequelize);
db.weatherData = weatherDataConstructor(sequelize, Sequelize);

export default db