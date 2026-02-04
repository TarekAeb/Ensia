from flask import Flask, request, render_template_string

app = Flask(__name__)

@app.route('/page5.html', methods=['POST'])
def pageE():
    username = request.form.get('username')
    return f"<h1>Welcome, {username}!</h1>"

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
