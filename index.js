const express = require('express');
const app = express(); 
const hbs = require("hbs");
const path = require("path");
//const mongoose = require('mongoose');
const res = require('express/lib/response');

//start
var bodyParser = require('body-parser');
var jsonParser = bodyParser.json();
//end

app.set('view engine','hbs');
const css_path = path.join(__dirname,'/public');
app.use(express.static(css_path));


//start
app.use(bodyParser.urlencoded({
    extended: true
}));
app.use(bodyParser.json());
//end


const user = require("./schema")
require("./db")
// const User = require("./UserModel")


app.get("/first",(req,res)=>{
    res.render('first'); 
})

app.get("/blog",(req,res)=>{
    res.render('blog'); 
})

app.get("/saloon",(req,res)=>{
    res.render('saloon'); 
})

app.get("/beauty",(req,res)=>{
    res.render('beauty'); 
})

app.get("/plumber",(req,res)=>{
    res.render('plumber'); 
})

app.get("/electric",(req,res)=>{
    res.render('electric'); 
})

app.get("/cleaning",(req,res)=>{
    res.render('cleaning'); 
})

app.get("/internet",(req,res)=>{
    res.render('internet'); 
})

app.get("/gardening",(req,res)=>{
    res.render('gardening'); 
})

app.get("/petcare",(req,res)=>{
    res.render('petcare'); 
})

app.get("/payment",(req,res)=>{
    res.render('payment'); 
})

app.get("/contact",(req,res)=>{
    res.render('contact'); 
})

hbs.registerPartials(__dirname+'/views','{{footer}}')
hbs.registerPartials(__dirname+'/views','{{nav}}')

app.post("/register", async(req,res)=>{

    try {

        var createddata = new user(req.body);

        createddata.save();

        console.log("USER REGISTERED");
        res.redirect("/first");

    } catch (error) {
        console.log("error");
        res.redirect("/blog");
    }
})




// app.post('/register', function (req, res) {
//     // create user in req.body
//     console.log(req.body);
//   })
  
app.listen('8000',()=>{
    console.log("Server is running");
})
