import db from "../models/index.js"
const WeatherData = db.weatherData;
const City = db.city;

export function getLatestWeatherData(req, res) {
    WeatherData.findOne({
        attributes: { exclude: ['createdAt', 'updatedAt'] },
        where: {city: req.params.city} 
    })
    .then(data => {
        console.log(data)
        res.status(200);
        res.send(data);
    })
    .catch(err => {
        console.log(`Cannot get latest data: ${err}`);
        res.status(404);
        res.send([]);
    })
}

export function getWeatherData(req, res) {
    City.findOne({
        where: {name: req.params.city},
        attributes: ['id']
    })
    .then(city => {
        WeatherData.findAll({
            where: {city: city.id},
            attributes: [req.params.factor],
            limit: 5
        })
        .then(data => {
            res.status(200);
            res.send(data);
        })
        .catch(err => {
            console.log(`Cannot get data: ${err}`);
            res.status(404);
            res.send([]);
        })
    })
    .catch(err => {
        console.log(`Cannot get data: ${err}`);
        res.status(404);
        res.send([]);
    })
    
}

/*
export function getLatestWeatherData(city) {
    WeatherData.findOne({
        attributes: { exclude: ['createdAt', 'updatedAt'] },
        where: {city: city} 
    })
    .then(data => {
        const resp = {
            data: data,
            status: 200
        }
        return resp
    })
    .catch(err => {
        console.log(`Cannot get latest data: ${err}`);
        const resp = {
            data: [],
            status: 404
        };
        return resp;
    })
}

export function getWeatherData(city, factor) {
    WeatherData.findAll({
        where: {city: city},
        attributes: [factor],
        limit: 5
    })
    .then(data => {
        const resp = {
            data: data,
            status: 200
        }
        return resp
    })
    .catch(err => {
        console.log(`Cannot get data: ${err}`);
        const resp = {
            data: [],
            status: 404
        };
        return resp;
    })
}
*/