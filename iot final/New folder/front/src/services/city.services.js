import http from "../http-common.js";

class CityService {
    getAll() {
        return http.get("/root/cities")
    }

    create(data) {
        return http.post("/root/cities", data)
    }
}

export default new CityService();