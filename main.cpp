#include <windows.h>
#include <WinCape.h>

WSTR_CON TEXTO_20_MINS = L"Ya pasaron 20 Minutos";
ui::Window wnApp;
ui::DeviceContext dcWnd;

//Callback functions
void wnApp_OnPaint(EVENT e);

int main(int argc, char** argv)
{
	//Call this to initiate some WinCape internal stuff
	w_cape::application.init();

	//Creating the app main window
	wnApp = w_cape::application.createWindow(
		L"Pruebas",
		L"Reglas 20-20-20",
		CAPE_RECT(400, 400, 300, 200),
		WindowStyles::DIALOG_FRAME
	);

	//Hiding window that holds message
	wnApp.hide();

	//Retrieving the main window device context
	dcWnd = wnApp.deviceContext();

	//setting up controls and callbacks
	wnApp.onPaint(wnApp_OnPaint);
	ui::Button btOk;
	wnApp.addButton(btOk, L"Ok", VEC_2I(100, 100));
	btOk.onClick([](const EVENT e){
		wnApp.hide();
	});
	wnApp.timer([](const EVENT e){
		wnApp.show();
	}, 1200000);

	//Finally run the main loop
	w_cape::application.run();

	//exit ok
	return 0;
}

void wnApp_OnPaint(const EVENT e){
	DRW_TXT_FMAT txFormat =
		ui::DrawTextFormats::SNG_LIN |
		ui::DrawTextFormats::HOR_CEN |
		ui::DrawTextFormats::VER_CEN;
	dcWnd.drawText(TEXTO_20_MINS, txFormat);
}
