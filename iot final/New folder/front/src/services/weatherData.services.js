import http from "../http-common.js";

class WeatherService {
    getLatestData(city) {
        return http.get(`/root/weather/${city}`)
    }

    getData(city, factor) {
        return http.get(`/root/weather/${city}/${factor}`)
    }        
}

export default new WeatherService();