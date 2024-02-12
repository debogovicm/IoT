import db from "../models/index.js"
const City = db.city;

export function getAllCities(req, res) {
    City.findAll({attributes: { exclude: ['createdAt', 'updatedAt'] }})
    .then(data => {
        console.log(data)
        res.status(200);
        res.send(data);        
    })
    .catch(err => {
        console.log(`Cannot get all cities: ${err}`);
        res.status(404);
        res.send([]);
    })
}

export function createCity(req, res) {
    console.log(req);
    res.status(200)
}