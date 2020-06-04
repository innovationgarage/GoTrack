// Everything that handles the reporting of positions via GPRS
class GPRSTask : public Task
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
} gprs_task;
