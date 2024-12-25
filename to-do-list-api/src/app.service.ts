import { Injectable } from '@nestjs/common';
import * as fs from 'fs';

@Injectable()
export class AppService {
  getData(): any {
    let words = fs.readFileSync('/home/tinstins/Desktop/ToDoListAPI/to-do-list-api/src/.ini/text', 'utf-8')
    let lines = words.split(/\r?\n/);
    return lines
  }


  updateData(data: any): any {
    let stringData = ""
    for (let item of data.lines) {
      stringData +=  item.toString() + "\n" 
    }
    stringData=stringData.trimEnd()
    fs.writeFileSync('/home/tinstins/Desktop/ToDoListAPI/to-do-list-api/src/.ini/text', stringData)
    return data
  }
}
