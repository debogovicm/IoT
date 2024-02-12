import express from "express"
import { getAllCities, createCity } from "../controllers/city.controller.js"

export default function(app) {
    var router = express.Router();

    router.get('/cities', getAllCities)
    router.post('/cities', createCity)

    /*
    router.get('/cities', (req, res) => {
        console.log('usao');
        const data = getAllCities();
        res.status(data.status);
        res.send(data.data);
    })
*/
    app.use('/root', router);
}