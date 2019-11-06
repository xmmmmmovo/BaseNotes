from quart import Quart
from quart import render_template
from jinja2 import Template

app = Quart("app")

@app.route('/hello')
@app.route('/')
async def hello_world():
    return await render_template('index.html')


if __name__ == '__main__':
    app.run(host='127.0.0.1',
            port=9000,
            debug=True,
            )
