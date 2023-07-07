const mongoose = require("mongoose");

const mongoURI = 'mongodb://aarshsingh512:1ArshSingh@ac-af5smxd-shard-00-00.tg8ureu.mongodb.net:27017,ac-af5smxd-shard-00-01.tg8ureu.mongodb.net:27017,ac-af5smxd-shard-00-02.tg8ureu.mongodb.net:27017/Foodzamern?ssl=true&replicaSet=atlas-tdx9ko-shard-0&authSource=admin&retryWrites=true&w=majority';

const mongoDB = async () => {
    try {
      await mongoose.connect(mongoURI);
      console.log('Connected!');
      let fetched_data = mongoose.connection.db.collection("food_items");
      let data=await fetched_data.find({}).toArray() 
      global.food_items =data;
      let foodCategory = await mongoose.connection.db.collection("foodCategory")
 
    } catch (error) {
      console.log('err: ', error);
    }
  };
  


module.exports = mongoDB;

