import './App.css';
import { Grid } from '@mui/material';
import Header from './components/header.js';
import InProgress from './components/inprogress.js';
import Repetoire from './components/repetoire.js';

function App() {
  return (
    <div className="App">
      <Header></Header>

      <Grid className="App-header">
        <InProgress></InProgress>
        <Repetoire></Repetoire>

        
      </Grid>

    </div>
  );
}

export default App;
