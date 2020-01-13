import React from "react";

import {render} from 'react-dom'

// 组件
class App extends React.Component {
    render(): React.ReactElement<any, string | React.JSXElementConstructor<any>> | string | number | {} | React.ReactNodeArray | React.ReactPortal | boolean | null | undefined {
        return <h1>test</h1>;
    }
}

render(
    <App/>,
    document.querySelector('#root')
)
