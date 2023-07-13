import React from 'react';
import logo from '../piano.jpeg';
import '../App.css';

const Header = (props) => {

    return (
        <div className='header'>
        <img src={logo} className='img'></img>
        <h1>piano tracker</h1>
      </div>
    )
}

export default Header