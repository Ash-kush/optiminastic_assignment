const express = require('express');
const nodemailer = require('nodemailer');
const bodyParser = require('body-parser');
const path = require('path');
// var smtpTransport = require('nodemailer-smtp-transport');
// const xoauth2 = require('xoauth2');
const app = express();

app.use(bodyParser.urlencoded({
    extended: true
}));

app.get('/', function(req, res) {
    res.sendFile(path.join(__dirname+'/Html_form.html'));
});

app.post('/', async function(req, res) {
    let mailTransporter = nodemailer.createTransport({
        service: 'gmail',
        auth: {
            user: '',
            pass: ''
        },
    });
    
    let mailDetails = {
        from: '',
        to: req.body.email,
        subject: req.body.subject,
        text: req.body.name + "\n" +req.body.message
    };
    
    mailTransporter.sendMail(mailDetails, function(err, data) {
        if(err) {
            console.log(err);
        } else {
            console.log('Email sent successfully');
        }
    });
})


app.listen(3000, function() {
    console.log("server is running")
});
