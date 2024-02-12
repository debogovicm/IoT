import express from "express";
import cors from "cors";

import cityRoutes from "./routes/city.routes.js"
import weatherDataRoutes from "./routes/weatherData.routes.js";

import db from './models/index.js'


const app = express();
var corsOptions = {
    origin: "http://localhost:6061"
};

app.use(cors(corsOptions));
app.use(express.json());
app.use(express.urlencoded());

cityRoutes(app);
weatherDataRoutes(app);

app.get("/root", (req, res) => {
  res.json({ message: "Welcome to bezkoder application." });
});

const PORT = process.env.PORT || 6060;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}.`);
});

db.sequelize.sync()
.then(() => { 
  console.log("Synced db.")
})
.catch(err => { console.log(`Failed to sync db: ${err}`)})

