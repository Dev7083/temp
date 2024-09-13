



### Node Basics:
Node.js is an open-source, cross-platform JavaScript runtime environment that allows developers to execute JavaScript code outside of a browser. It is built on Chrome's V8 JavaScript engine, which enables high-performance execution of JavaScript code.



---

### Express Basics:
Express.js is a popular web application framework for Node.js, offering robust features for building web applications, including single-page, multi-page, and API-driven applications. This tutorial introduces you to the basics of Express.js, its purpose, key features, and benefits for building web applications and APIs.





Installation:

```
npm init
```
```
npm install express --save
```
Basic Server Setup:

```javascript
// Import Express.js module
const express = require('express');

// Initialize the Express application
const app = express();

// Define the port number for the server to listen on
const port = 3000;

// Define a route for the root URL ('/') and specify the response
app.get('/', (req, res) => {
  res.send('Hello, World!'); // Send 'Hello, World!' as the response
});

// Start the server and have it listen on the defined port
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`); // Log a message to the console indicating the server is running
});
```
Using Nodemon:

Nodemon is a development tool that automatically restarts the Node.js application when it detects changes to any project file

- Insalling Nodemon as a dev dependency
```
npm install --save-dev nodemon
```
---

### Middleware


Middleware in Express.js refers to functions that have access to the request and response objects, as well as the next middleware function in the application’s request-response cycle. These functions can perform various operations, including executing code, modifying the request and response objects, terminating the request-response cycle, handling cookies, logging requests, and passing control to subsequent middleware functions.

#### Types of Middleware
1.  **Application-level middleware:** Binds to an instance of the app object.
2. **Router-level middleware:** Binds to an instance of `express.Router()`  .
3. **Error-handling middleware:** Special middleware that handles errors.
4. **Built-in middleware:** Provided by Express, such as `express.json()`   and `express.static()`  .
5. **Third-party middleware:** Provided by the community, like **Morgan**, for logging.


Implementation:

- Application level 
Application-level middleware is attached to an instance of the app object through `app.use()` and `app.METHOD()`, where the `METHOD` is an HTTP method.

```
const express = require('express');
const app = express();

// Application-level middleware
app.use((req, res, next) => {
  console.log('Application-level middleware.');
  console.log(`Request method: ${req.method}, URL: ${req.url}, Time: ${Date.now()}`);
  next(); // Proceed to the next middleware
});

// Route handler for the root URL
app.get('/', (req, res) => {
  res.send('Hello, World!');
});

// Start the server
app.listen(3000, () => {
  console.log('The server is running on port 3000.');
});
```
- Route Level Middleware
```
const express = require('express');
const app = express();
const router = express.Router();

// Middleware function for router
router.use((req, res, next) => {
  console.log('Request URL:', req.originalUrl);
  next(); // Proceed to the next middleware
});

// Route handler
router.get('/', (req, res) => {
  res.send('Router Middleware');
});

app.use('/router', router); // Apply router middleware

app.listen(3000, () => {
  console.log('The server is running on port 3000.');
});
```
- Built in Middleware
Express provides built-in middleware to handle common tasks. For instance, `express.json()` and `express.urlencoded()` parse JSON and URL-encoded data.

```
const express = require('express');
const app = express();

// Built-in middleware to parse JSON
app.use(express.json());

app.post('/data', (req, res) => {
  res.send(`Received data: ${JSON.stringify(req.body)}`);
});

app.listen(3000, () => {
  console.log('The server is running on port 3000.');
});
```
Middleware functions allows to build more modular, maintainable, and robust web applications.

---

### Request & Response Object
Express.js utilizes request and response objects to handle incoming HTTP requests and outgoing HTTP responses. These objects are essential for managing interactions in developing robust and efficient web applications. 



Request Object:

The request object, often abbreviated as `req`, represents the HTTP request and includes various properties that provide details about the incoming request.

Prop & Methods of Request Object

- `req.query` : Contains the URL query parameters.
- `req.params` : Contains route parameters.
- `req.body` : Contains data sent in the request body (requires body-parser middleware).
- `req.method` : The HTTP method used (GET, POST, etc.).
- `req.url` : The URL of the request.
- `req.headers` : Contains the headers of the request.
Response Object:

The response object, commonly abbreviated as `res`, represents the HTTP response that an Express app sends when it gets an HTTP request. It includes methods for setting the response status, headers, and body.



Prop & Methods of Response Object

- `res.send()` : Sends a response of various types.
- `res.json()` : Sends a JSON response.
- `res.status()` : Sets the HTTP status for the response.
- `res.redirect()` : Redirects to a specified URL.
- `res.render()` : Renders a view template.
- `res.sendFile()` : Sends a file as an octet stream.
Request and response objects in Express.js,  are essential for handling client-server communication.

These objects can manage data retrieval, send appropriate responses, and handle errors efficient

---

### Routing
Routing in Express.js refers to how an application's endpoints (URIs) respond to client requests. This tutorial will cover the basics of Express routing.



Routing in Express.js defines URL patterns (endpoints) and links them with specific actions or resources within your web application. It allows users to navigate your application based on URLs. Express uses the app object to define routes.



```
app.METHOD(PATH, HANDLER)
```
Each route consists of three parts:

- **METHOD**: Specifies the HTTP request method. Common methods include GET, POST, PUT, DELETE, etc.
- **PATH**: Defines the URL pattern for the route. (e.g., /about, /contact).
- **HANDLER**: The function that is executed when a route is matched. It typically sends a response back to the client.
```
const express = require('express'); // Import express module
const app = express(); // Create express app
const port = 3000; // Define port

// Define a route for the root URL ('/') with a GET request method
app.get('/', (req, res) => {
    // Send a response to the client
    res.send('Welcome to the Home Page!');
});

// Define a route for the '/about' URL with a GET request method
app.get('/about', (req, res) => {
    // Send a response to the client
    res.send('About Us');
});

// Define a route for the '/contact' URL with a GET request method
app.get('/contact', (req, res) => {
    // Send a response to the client
    res.send('Contact Us');
});

// Start server
app.listen(port, () => console.log(`Server is running at http://localhost:${port}`));
```
Explanation:

- The root route (`/` ) handles GET requests for the root URL. When a request is received at this URL, the handler function sends 'Welcome to the Home Page!' as a response.
- The about route (`/about` ) handles GET requests for the `/about`  URL. When a GET request is made to `/about` , the handler function sends 'About Us' as a response.
- The contact route (`/contact` ) handles GET requests for the `/contact`  URL. When a request is received at this URL, the handler function sends 'Contact Us' as a response.


