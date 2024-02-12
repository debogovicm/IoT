import React, { Component } from 'react';
import CityService from '../services/city.services.js';

export default class AddCity extends Component {
  constructor(props) {
    super(props)

    this.onChangeCityName = this.onChangeCityName.bind(this);
    this.onChangeCityPort = this.onChangeCityPort.bind(this);
    this.saveCity = this.saveCity.bind(this);
    this.newCity = this.newCity.bind(this);

    this.state = {
      cityData: {
        port: null,
        name: "",
        submitted: false
      }
    }
  }

  onChangeCityName(e) {
    this.setState(prevState => {
      return {
        cityData: {
          ...prevState.cityData,
          name: e.target.value
        }
      }
    })
  }

  onChangeCityPort(e) {
    this.setState(prevState => {
      return {
        cityData: {
          ...prevState.cityData,
          port: e.target.value
        }
      }
    })
  }

  saveCity() {
    var data = {
      id: this.state.cityData.port,
      name: this.state.cityData.name
    }

    CityService.create(data)
    .then(response => {
      this.setState({
        cityData: {
          id: response.data.id,
          name: response.data.name,
          submitted: true
        }
      });
      console.log(response.data);
    })
    .catch(err => console.log(err));
  }

  newCity() {
    this.setState({
      cityData: {
        id: null,
        name: "",
        submitted: false
      }
    })
  }


  render() {
      return (
        <div className="submit-form">
          <h3>City form</h3>
          <div className='city-form'>
            {this.state.cityData.submitted ? (
              <div>
                  <h4>You submitted new city successfully!</h4>
                  <button className="btn btn-success" onClick={this.newCity}>
                    Add another city
                  </button>
              </div>
              ) : (
              <div>
                  <div className="form-group">
                    <label htmlFor="cityName">Name:</label>
                    <input
                        type="text"
                        className="form-control"
                        id="cityName"
                        required
                        value={this.state.cityData.name}
                        onChange={this.onChangeCityName}
                        name="cityName"
                    />
                  </div>

                  <div className="form-group">
                    <label htmlFor="cityPort">Post number:</label>
                    <input
                        type="text"
                        className="form-control"
                        id="cityPort"
                        required
                        value={this.state.cityData.port}
                        onChange={this.onChangeCityPort}
                        name="cityPort"
                    />
                  </div>               

                  <br/>
                  <button onClick={this.saveCity} className="btn btn-success">
                      Submit
                  </button>
              </div>
            )}
          </div>
        </div>
      )
  }
}