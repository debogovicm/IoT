import React, { Component } from 'react';
import { Link } from "react-router-dom";
import WeatherService from '../services/weatherData.services.js'
import { withRouter } from '../common/with-router.js'; 

import Graph from './graph.component.js'

class CityDetails extends Component {
    constructor(props) {
        super(props)

        this.onTemperature = this.onTemperature.bind(this);
        this.onUVindex = this.onUVindex.bind(this);
        this.onHumidity = this.onHumidity.bind(this);
        this.onCloudness = this.onCloudness.bind(this);
        this.onWindSpeed = this.onWindSpeed.bind(this);
        this.onWindDirection = this.onWindDirection.bind(this);

        this.state = {
          city: this.props.router.params.city,
          temperature: {
            data: [],
            active: false
          },
          UVindex: {
            data: [],
            active: false
          },
          humidity: {
            data: [],
            active: false
          },
          cloudness: {
            data: [],
            active: false
          },
          windSpeed: {
            data: [],
            active: false
          },
          windDirection: {
            data: [],
            active: false
          }
        }
    }

    convertDataToArray(data) {
      var arr = [];
      data.forEach(dict => {
        for (var key in dict) {
          if (dict.hasOwnProperty(key)) {
            arr.push(dict[key])
          }
        }        
      });
      return arr;
    }

    onTemperature() {
      if (!this.state.temperature.active) {
        WeatherService.getData(this.state.city, 'temperature')
        .then(response => {          
          this.setState({
            temperature: {
                data: this.convertDataToArray(response.data),
                active: true
              }
          })
        })
        .catch(err => console.log(err));
      } else {
        this.setState({
          temperature: {
              data: [],
              active: false
            }
        })
      }   
    }


    onUVindex() {
      if (!this.state.UVindex.active) {
        WeatherService.getData(this.state.city, 'UVindex')
        .then(response => {
          this.setState({
            UVindex: {
                data: this.convertDataToArray(response.data),
                active: true
              }
          })
        })
        .catch(err => console.log(err));
      } else {
        this.setState({
          UVindex: {
              data: [],
              active: false
            }
        })
      }      
    }

    onHumidity() {
      if (!this.state.humidity.active) {
        WeatherService.getData(this.state.city, 'humidity')
        .then(response => {
          this.setState({
            humidity: {
                data: this.convertDataToArray(response.data),
                active: true
              }
          })
        })
        .catch(err => console.log(err));
      } else {
        this.setState({
          humidity: {
              data: [],
              active: false
            }
        })
      }      
    }

    onCloudness() {
      if (!this.state.cloudness.active) {
        WeatherService.getData(this.state.city, 'cloudCover')
        .then(response => {
          this.setState({
            cloudness: {
                data: this.convertDataToArray(response.data),
                active: true
              }
          })
        })
        .catch(err => console.log(err));
      } else {
        this.setState({
          cloudness: {
              data: [],
              active: false
            }
        })
      }      
    }

    onWindSpeed() {
      if (!this.state.windSpeed.active) {
        WeatherService.getData(this.state.city, 'windSpeed')
        .then(response => {
          this.setState({
            windSpeed: {
                data: this.convertDataToArray(response.data),
                active: true
              }
          })
        })
        .catch(err => console.log(err));
      } else {
        this.setState({
          windSpeed: {
              data: [],
              active: false
            }
        })
      }      
    }

    onWindDirection() {
      if (!this.state.windDirection.active) {
        WeatherService.getData(this.state.city, 'windDirection')
        .then(response => {
          this.setState({
            windDirection: {
                data: this.convertDataToArray(response.data),
                active: true
              }
          })
        })
        .catch(err => console.log(err));
      } else {
        this.setState({
          windDirection: {
              data: [],
              active: false
            }
        })
      }     
    }

    render() {
      const {city, temperature, UVindex, humidity, cloudness, 
             windSpeed, windDirection} = this.state;

      return(
        <div>
          <div className="list row">
            <div className="col-md-6">
                <h4>Weather in {city}</h4>

                <ul className="list-group">

                  {/* ---------- Temperature ---------- */}
                  <li
                  className={
                    "list-group-item " +
                    (temperature.active ? "active" : "")
                  }
                  onClick={() => this.onTemperature()}
                  >
                  <p>Temperature</p>
                  </li>
                  {temperature.active ? (
                    <div>
                      <br />
                      {Graph(temperature.data, 'Temperature graph', 'temperature', -20, 40)}
                    </div>
                  ) : (
                      <div></div>
                  )}

                  {/* ---------- UV index ---------- */}
                  <li
                  className={
                    "list-group-item " +
                    (UVindex.active ? "active" : "")
                  }
                  onClick={() => this.onUVindex()}
                  >
                  <p>UV index</p>
                  </li>
                  {UVindex.active ? (
                    <div>
                      <br />
                      {Graph(UVindex.data, 'UV index graph', 'UVindex', 0, 7)}
                    </div>
                  ) : (
                      <div></div>
                  )}

                  {/* ---------- Humidity ---------- */}
                  <li
                  className={
                    "list-group-item " +
                    (humidity.active ? "active" : "")
                  }
                  onClick={() => this.onHumidity()}
                  >
                  <p>Humidity</p>
                  </li>
                  {humidity.active ? (
                    <div>
                      <br />
                      {Graph(humidity.data, 'Humidity graph', 'humidity', 0, 100)}
                    </div>
                  ) : (
                      <div></div>
                  )}

                  {/* ---------- Cloudness ---------- */}
                  <li
                  className={
                    "list-group-item " +
                    (cloudness.active ? "active" : "")
                  }
                  onClick={() => this.onCloudness()}
                  >
                  <p>Cloudness</p>
                  </li>
                  {cloudness.active ? (
                    <div>
                      <br />
                      {Graph(cloudness.data, 'Cloudness graph', 'cloudness', 0, 100)}
                    </div>
                  ) : (
                      <div></div>
                  )}

                  {/* ---------- Wind Speed ---------- */}
                  <li
                  className={
                    "list-group-item " +
                    (windSpeed.active ? "active" : "")
                  }
                  onClick={() => this.onWindSpeed()}
                  >
                  <p>Wind Speed</p>
                  </li>
                  {windSpeed.active ? (
                    <div>
                      <br />
                      {Graph(windSpeed.data, 'Wind speed graph', 'windSpeed', 0, 100)}
                    </div>
                  ) : (
                      <div></div>
                  )}

                  {/* ---------- Wind Direction ---------- */}
                  <li
                  className={
                    "list-group-item " +
                    (windDirection.active ? "active" : "")
                  }
                  onClick={() => this.onWindDirection()}
                  >
                  <p>Wind Direction</p>
                  </li>
                  {windDirection.active ? (
                    <div>
                      <br />
                      {Graph(windDirection.data, 'Wind direction graph', 'windDirection', 0, 8, true)}
                    </div>
                  ) : (
                      <div></div>
                  )}

                </ul>

                <Link
                    to={"/root/"}
                    className="m-3 btn btn-sm btn-danger"
                >
                    Return to main page
                </Link>

            </div>
          </div>
        </div>
      )
    }
}

export default withRouter(CityDetails)