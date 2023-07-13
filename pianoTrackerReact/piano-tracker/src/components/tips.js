import React from 'react';
import '../App.css';
import {
    Menu,
  } from 'semantic-ui-react'

const Tips = (props) => {

    return (
        <div style={{justifyContent: 'center'}}>
            <h2 style={{color: 'dimgray'}}>practice reminders</h2>
            <div>
                <Menu vertical fluid>
                    <Menu.Item>
                        <p>Cras justo odio</p>
                    </Menu.Item>
                    <Menu.Item>
                        <p>Vestibulum at eros</p>
                    </Menu.Item>
                </Menu>
            </div>
      </div>
    )
}

export default Tips