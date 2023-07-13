import './App.css';
import Completed from './components/completed';
import Header from './components/header.js';
import InProgress from './components/inprogress';
import {
  Grid,
  Menu,
} from 'semantic-ui-react'
import Tips from './components/tips';
import Inspo from './components/inspo';

function App() {
  return (
    <div className="App" style={{backgroundColor: '#faf0e6'}}>
      <Header></Header>
      <Grid container style={{ padding: '5em 0em' }}>
        <Grid columns={2}>
            <Grid.Column>
             <InProgress></InProgress>
            </Grid.Column>
            <Grid.Column>
              <Completed></Completed>
            </Grid.Column>
          </Grid>
        </Grid>

      <Tips></Tips>

      <div style={{padding: '1em' }}></div>
      <Inspo></Inspo>

    </div>
  );
}

export default App;
