import React from 'react';
import logo from '../piano.jpeg';
import '../App.css';

const Header = (props) => {

    return (
        <div className='header'>
        <img src={logo} className='img'></img>
        <h2>piano tracker</h2>
      </div>
    )
}

export default Header