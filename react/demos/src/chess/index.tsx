import React from 'react'
import './index.css'

type sp = {
    value: number | string;
    onClick: () => void;
}

function Square(props: sp) {
  return (
    <button
      className='square'
      onClick={() => props.onClick()}
    >
      {props.value}
    </button>
  )
};

type bp = {
    squares: bs['squares'];
    onClick: (i: number) => void;
}

type bs = {
    squares: number[] | string[];
}

class Board extends React.Component<bp> {
  renderSquare(i: number) {
    return <Square
      value={this.props.squares[i]}
      onClick={() => this.props.onClick(i)}
    />
  }

  render() {
    return (
      <div>
        <div className='board-row'>
          {this.renderSquare(0)}
          {this.renderSquare(1)}
          {this.renderSquare(2)}
        </div>
        <div className='board-row'>
          {this.renderSquare(3)}
          {this.renderSquare(4)}
          {this.renderSquare(5)}
        </div>
        <div className='board-row'>
          {this.renderSquare(6)}
          {this.renderSquare(7)}
          {this.renderSquare(8)}
        </div>
      </div>
    )
  }
}

function calculateWinner(squares: number[] | string[]) {
  const lines = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6]
  ]

  for (let i = 0; i < lines.length; i++) {
    const [a, b, c] = lines[i]
    if (squares[a] && squares[a] === squares[b] && squares[a] === squares[c]) {
      return squares[a]
    }
  }
  return null
}

type gs = {
    history: bs[];
    xIsNext: boolean;
    stepNumber: number;
}

export class Game extends React.Component<{}, gs> {
  constructor(props: object) {
    super(props)
    this.state = {
      history: [{
        squares: Array(9).fill(null)
      }],
      xIsNext: true,
      stepNumber: 0
    }
  }

  handleClick(i: number) {
    const history = this.state.history.slice(0, this.state.stepNumber + 1)
    const current = history[history.length - 1]
    const squares = current.squares.slice()

    if (squares[i] || calculateWinner(squares)) {
      return
    }
    squares[i] = this.state.xIsNext ? 'X' : 'O'
    this.setState(
      {
        history: history.concat([
          {
            squares: squares
          }
        ]),
        stepNumber: history.length,
        xIsNext: !this.state.xIsNext
      }
    )
  }

  jumpTo(step: number) {
    this.setState(
      {
        stepNumber: step,
        xIsNext: (step % 2) === 0
      }
    )
  }

  render() {
    const history = this.state.history
    const current = history[this.state.stepNumber]

    const winner = calculateWinner(current.squares)

    const moves = history.map((sqare: bs, index: number) => {
      const desc = index
        ? 'Go to move #' + index
        : 'Go to game start'

      return (
        <li key={index}>
          <button onClick={() => this.jumpTo(index)}>
            {desc}
          </button>
        </li>
      )
    })

    const status = winner
      ? ('Winner: ' + winner)
      : ('Next player: ' + (this.state.xIsNext ? 'X' : 'O'))

    console.log(this.state)

    return (
      <div className='game'>
        <div className='game-board'>
          <Board
            squares={current.squares}
            onClick={(i) => this.handleClick(i)}
          />
        </div>
        <div className='game-info'>
          <div>{status}</div>
          <ol>{moves}</ol>
        </div>
      </div>
    )
  }
}
