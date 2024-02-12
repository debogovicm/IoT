import React, { Component } from 'react'
import { Routes, Route, Link } from 'react-router-dom';
import "bootstrap/dist/css/bootstrap.min.css";
import './App.css';

import ListCities from './components/citylist.component.js'
import CityDetails from './components/citydetails.component.js'
import AddCity from './components/add.component.js'

class App extends Component {
  render() {
    return(
      <div>
        <nav className='navbar navbar-expand navbar-dark bg-dark'>
          <Link to={"/root"} className="navbar-brand">
            Weather Forecast
          </Link>
          <div className="navbar-nav mr-auto">
            <li className="nav-item">
              <Link to={"/root"} className="nav-link">
                Cities
              </Link>
            </li>
            <li className="nav-item">
              <Link to={"/add"} className="nav-link">
                Add
              </Link>
            </li>
          </div>
        </nav>

        <div className="container mt-3">
          <Routes>
            <Route path="/" element={<ListCities/>} />
            <Route path="/root" element={<ListCities/>} />
            <Route path="/add" element={<AddCity/>} />
            <Route path="/root/city/:city" element={<CityDetails/>} />
          </Routes>
        </div>

      </div>
    )
  }
}

export default App;
