import express from "express"
import { getLatestWeatherData, getWeatherData } from '../controllers/weatherData.controller.js'

export default function(app) {
    var router = express.Router();

    router.get('/weather/:city/:factor', getWeatherData)

    router.get('/weather/:city', getLatestWeatherData)

    /*
    router.get('/weather?:city', (req, res) => {
        const data = getLatestWeatherData(req.params.city)
        res.status(data.status);
        res.send(data.data);
    })

    router.get('/weather?:city&:factor', (req, res) => {
        const data = getWeatherData(req.params.city, req.params.factor)
        res.status(data.status);
        res.send(data.data);
    })
    */

    app.use('/root', router);
}