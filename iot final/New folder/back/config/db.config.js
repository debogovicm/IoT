const conf = {
    HOST: "localhost",
    USER: "root",
    PASSWORD: "123456",
    DB: "WeatherDatabase",
    dialect: "mysql",
    pool: {
        max: 5,
        min: 0, 
        acquire: 30000,
        idle: 10000
    }
}

export default conf