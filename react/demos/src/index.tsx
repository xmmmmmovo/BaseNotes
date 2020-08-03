import React from 'react'
import ReactDOM from 'react-dom'
import './index.css'
import { Link, Route, BrowserRouter as Router, Switch } from 'react-router-dom'
import { Game } from './chess'
import { Dragger } from './dragger'

ReactDOM.render(
  <Router>
    <nav>
      <h1>
                demos~
      </h1>
      <ul>
        <li>
          <Link to={'/chess'}>chess demo</Link>
        </li>
        <li>
          <Link to={'/dragger'}>dragger demo</Link>
        </li>
      </ul>
    </nav>
    <Switch>
      <Route path={'/chess'}>
        <Game/>
      </Route>
      <Route path={'/dragger'}>
        <Dragger/>
      </Route>
    </Switch>
  </Router>,
  document.getElementById('root')
)
