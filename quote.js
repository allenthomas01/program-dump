/*
MONGOOSE PROGRAM FOR LOCAL MONGODB WHICH TAKES INPUT STRING (QUOTES) FROM USER THROUGH CONSOLE
AND SAVES IT TO COLLECTION 'momentum' IN 'Quotes' DATABASE 
*/

const mongoose = require('mongoose');
const readline = require('readline');

// Connect to MongoDB
mongoose.connect('mongodb://127.0.0.1:27017/Quotes', { useNewUrlParser: true, useUnifiedTopology: true });

// Create a Quote schema
const quoteSchema = new mongoose.Schema({
  quote: {
    type: String,
    required: true,
    unique: true
  }
});

// Create a Quote model
const Quote = mongoose.model('Quote', quoteSchema, 'momentum');

// Create readline interface for user input
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Prompt user for a quote to insert
rl.question('Enter the quote to insert: ', async (quote) => {
  // Close the readline interface
  rl.close();

  try {
    // Check if the quote already exists in the database
    const existingQuote = await Quote.findOne({ quote });

    if (existingQuote) {
      console.log('Duplicate quote found in the database.');
      mongoose.disconnect(); // Close the MongoDB connection
      return;
    }

    // Create a new quote document and save it to the database
    const newQuote = new Quote({ quote });
    await newQuote.save();
    console.log('Quote inserted successfully.');
    mongoose.disconnect(); // Close the MongoDB connection
  } catch (error) {
    console.error('Error inserting quote:', error);
    mongoose.disconnect(); // Close the MongoDB connection
  }
});
