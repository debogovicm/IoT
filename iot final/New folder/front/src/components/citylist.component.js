import React, { Component } from 'react';
import { Link } from "react-router-dom";
import CityService from '../services/city.services.js'
import WeatherService from '../services/weatherData.services.js'

export default class CityList extends Component {
    constructor(props) {
        super(props)

        this.retreiveCities = this.retreiveCities.bind(this);
        this.setActiveCity = this.setActiveCity.bind(this);

        this.retreiveWeatherData = this.retreiveWeatherData.bind(this);

        this.state = {
            cities: [],
            currentCity: null,
            currentCityIndex: -1,

            temperature: 0,
            UVindex: 0,
            humidity: 0,
            cloudness: 0,
            windSpeed: 0, 
            windDirection: ""
        }
    }

    componentDidMount() {
        this.retreiveCities();
    }

    retreiveCities() {
        CityService.getAll()
        .then(response => {
            this.setState({
                cities: response.data
            });
        })
        .catch(err => console.log(err));
    }


    retreiveWeatherData(city) {
      WeatherService.getLatestData(city)
      .then(response => {
        this.setState({
          temperature: response.data.temperature,
          UVindex: response.data.UVindex,
          humidity: response.data.humidity,
          cloudness: response.data.cloudCover,
          windSpeed:response.data.windSpeed,
          windDirection: response.data.windDirection 
        })
      })
      .catch(err => console.log(`retreiveWeatherData doesn't work (citylist.component/51): ${err}`))
    }
    
    setActiveCity(city, index) {
        this.setState({
            currentCity: city,
            currentCityIndex: index
        });
        this.retreiveWeatherData(city.id);
    }

    render() {
        const { cities, currentCity, currentCityIndex,
                temperature, UVindex, humidity, cloudness, windSpeed, windDirection } = this.state; 

        return(
          <div>
            <div className="list row">
              <div className="col-md-6">
                <h4>Cities</h4>

                <ul className="list-group">
                    {cities && cities.map((city, index) => (
                        <li
                        className={
                            "list-group-item " +
                            (index === currentCityIndex ? "active" : "")
                        }
                        onClick={() => this.setActiveCity(city, index)}
                        key={index}
                        >
                        {city.name} - {city.id} 
                        </li>
                    ))}
                </ul>
              </div>

              <div className="col-md-6">
                {currentCity ? (
                  <div>
                    <h4>Current weather in {currentCity.name}</h4>
                    <div>
                      <label>
                      <strong>temperature:</strong>
                      </label>{" "}
                      {temperature}
                    </div>
                    <div>
                      <label>
                      <strong>UV index:</strong>
                      </label>{" "}
                      {UVindex}
                    </div>
                    <div>
                      <label>
                      <strong>humidity:</strong>
                      </label>{" "}
                      {humidity}
                    </div>
                    <div>
                      <label>
                      <strong>cloudness:</strong>
                      </label>{" "}
                      {cloudness}
                    </div>
                    <div>
                      <label>
                      <strong>Wind speed:</strong>
                      </label>{" "}
                      {windSpeed}
                    </div>
                    <div>
                      <label>
                      <strong>Wind direction:</strong>
                      </label>{" "}
                      {windDirection}
                    </div>
                    
                    <Link
                        to={"/root/city/" + currentCity.name}
                    >
                        View current weather details
                    </Link>
                  </div>
                ) : (
                    <div>
                        <br />
                        <p>Please click on a city...</p>
                    </div>
                )}
              </div>
            </div> 
          </div>
        )
    }

}
