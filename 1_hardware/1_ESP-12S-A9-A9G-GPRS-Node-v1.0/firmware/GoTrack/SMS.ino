// Check and answer to SMS
class SMSTask : public Task
{
  protected:
    void setup()
    {

    }

    void loop()
    {
      delay(1000);
    }

  private:
    uint8_t state;
} sms_task;
