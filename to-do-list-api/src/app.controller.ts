import { Body, Controller, Get ,Post, Query} from '@nestjs/common';
import { AppService } from './app.service';

@Controller()
export class AppController {
  constructor(private readonly appService: AppService) {}

  @Get()
  getData(): string[] {
    return this.appService.getData();
  }

  @Post()
  updateData(@Body() data:any): string {
    return this.appService.updateData(data);
  }

}
