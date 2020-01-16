import React from "react";

import './login.less'

export default class Login extends React.Component<any, any> {
    render() {
        return(
            <div className={"login"}>
                <header className={"login-header"}>
                    <h1>社区后台</h1>
                </header>
                <section className={"login-content"}>
                </section>
            </div>
        )
    }
}
