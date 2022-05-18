const mongoose = require("mongoose")

const UserSchema = mongoose.Schema({
    userid: {
        type: String,
        required: true
    },
    email : {
        type: String,
        required: true,
        unique:true
    },
    password : {
        type : String,
        required: true
    },
   
}, 
[])


// creating a user collection
// const UserModel = mongoose.model('User', UserSchema)

module.exports = mongoose.model('User', UserSchema)